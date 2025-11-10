<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="3">
		<v-card-title>
			<v-row>
				<v-col cols="8">
					<div>{{tag.Cpt}}</div>
				</v-col>
				<v-col cols="4" align="end">
					&#160;
					<v-btn
						v-if="statshr.srefIxWzskVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButClaimClick')"
						:value="1"
						:disabled="!statshr.ButClaimActive"
					>
						<v-icon color="white">{{contapp.ButClaimOn ? 'mdi-cog' : 'mdi-cog-off'}}</v-icon>
					</v-btn>
					&#160;&#160;
					&#160;
					<v-btn
						v-if="statshr.srefIxWzskVExpstate=='mind'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButRegularizeClick')"
						:value="1"
					>
						<v-icon color="white">mdi-plus-circle</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statshr.srefIxWzskVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButMinimizeClick')"
						:value="1"
					>
						<v-icon color="white">mdi-minus-circle</v-icon>
					</v-btn>
				</v-col>
			</v-row>
		</v-card-title>

		<v-card-text
			v-if="statshr.srefIxWzskVExpstate=='regd'"
		>
			<h3
				class="text-5 my-1"
			>
				{{tag.HdgTrk}}
			</h3>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfTfr"
				:label="tag.CptTfr"
				:disabled="!statshr.TxfTfrActive"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtTst"
				:label="tag.CptTst"
			/>

			<v-row class="my-1">
				<v-col>
					<v-btn
						v-on:click="handleButClick('ButTsrClick')"
						:disabled="!statshr.ButTsrActive"
						class="my-1"
						color="primary"
					>
						{{tag.ButTsr}}
					</v-btn>
					&#160;
					<v-btn
						v-on:click="handleButClick('ButTspClick')"
						:disabled="!statshr.ButTspActive"
						class="my-1"
						color="primary"
					>
						{{tag.ButTsp}}
					</v-btn>
				</v-col>
			</v-row>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtTtf"
				:label="tag.CptTtf"
			/>

		</v-card-text>
	</v-card>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWzskVtrDebug',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWzskVtrDebug.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWzskInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit('request', {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			handleButClick: function(consref) {
				const dpchapp = {
					"DpchAppWzskVtrDebugDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": consref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWzskVtrDebug"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWzskVtrDebugData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWzskVtrDebugData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWzskVtrDebug) this.contiac = dpcheng.ContIacWzskVtrDebug;
				if (dpcheng.ContInfWzskVtrDebug) this.continf = dpcheng.ContInfWzskVtrDebug;
				if (dpcheng.StatShrWzskVtrDebug) this.statshr = dpcheng.StatShrWzskVtrDebug;
				if (dpcheng.TagWzskVtrDebug) {
					Wzsk.unescapeBlock(dpcheng.TagWzskVtrDebug);
					this.tag = dpcheng.TagWzskVtrDebug;
				}
				if (dpcheng.ContInfWzskVtrDebug) {
					if (!this.continf.ButClaimOn) this.contapp.ButClaimOn = 0;
					else this.contapp.ButClaimOn = 1;
				}
				/*
				<!-- IP mergeDpchEngData - END -->
				*/
			},

			handleReply: function(obj) {
				if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
				else if (obj.then == "handleDpchAppDataDoReply") this.handleDpchAppDataDoReply(obj.srefIxWzskVDpch, obj.dpcheng);
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleDpchAppDataDoReply: function(srefIxWzskVDpch, dpcheng) {
				if (srefIxWzskVDpch == "DpchEngWzskVtrDebugData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWzskVDpch == "DpchEngWzskVtrDebugData") this.mergeDpchEngData(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {
		},

		data: () => ({
			initdone: false,

			/*
			*/
			contiac: null,

			continf: null,

			statshr: null,

			tag: null,

			contapp: {
				ButClaimOn: 0,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
