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
			<div
				class="my-1"
				style="height:500px"
			>
				<!-- IP divTre - INSERT -->
			</div>

			<v-row class="my-1">
				<v-col>
					<v-btn
						v-on:click="handleButClick('ButPlayClick')"
						:disabled="!statshr.ButPlayActive"
						fab
						small
						light
						color="primary"
					>
						<v-icon color="white">mdi-play</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-on:click="handleButClick('ButStopClick')"
						:disabled="!statshr.ButStopActive"
						fab
						small
						light
						color="primary"
					>
						<v-icon color="white">mdi-stop</v-icon>
					</v-btn>
				</v-col>
			</v-row>

			<v-divider/>

			<h3
				class="text-5 my-1"
			>
				{{tag.HdgAcq}}
			</h3>

			<v-slider
				class="my-1"
				v-model="contiac.SldAin"
				v-on:end='updateEng(["contiac"])'
				:label="tag.CptAin"
				:min="statshr.SldAinMin"
				:max="statshr.SldAinMax"
				:disabled="!statshr.SldAinActive"
			>
				<template v-slot:append>
					<v-text-field
						v-model="contiac.SldAin"
						v-on:change='updateEng(["contiac"])'
						class="mt-0 pt-0"
						hide-details
						single-line
						type="number"
						style="width: 80px"
					/>
				</template>
			</v-slider>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtAst"
				:label="tag.CptAst"
			/>

			<v-text-field
				v-if="statshr.TxtAoaAvail"
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtAoa"
				:label="tag.CptAoa"
			/>

			<v-row class="my-1">
				<v-col>
					<v-btn
						v-on:click="handleButClick('ButAsrClick')"
						:disabled="!statshr.ButAsrActive"
						class="my-1"
						color="primary"
					>
						{{tag.ButAsr}}
					</v-btn>
					&#160;
					<v-btn
						v-on:click="handleButClick('ButAirClick')"
						:disabled="!statshr.ButAirActive"
						class="my-1"
						color="primary"
					>
						{{tag.ButAir}}
					</v-btn>
				</v-col>
			</v-row>

		</v-card-text>
	</v-card>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWzskLiv3DView',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWzskLiv3DView.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWzskLiv3DViewDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWzskLiv3DView"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWzskLiv3DViewData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWzskLiv3DViewData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWzskLiv3DView) this.contiac = dpcheng.ContIacWzskLiv3DView;
				if (dpcheng.ContInfWzskLiv3DView) this.continf = dpcheng.ContInfWzskLiv3DView;
				if (dpcheng.StatAppWzskLiv3DView) this.statapp = dpcheng.StatAppWzskLiv3DView;
				if (dpcheng.StatShrWzskLiv3DView) this.statshr = dpcheng.StatShrWzskLiv3DView;
				if (dpcheng.TagWzskLiv3DView) {
					Wzsk.unescapeBlock(dpcheng.TagWzskLiv3DView);
					this.tag = dpcheng.TagWzskLiv3DView;
				}
				if (dpcheng.ContInfWzskLiv3DView) {
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
				if (srefIxWzskVDpch == "DpchEngWzskLiv3DViewData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/

			handleDpchEngWzskLiv3DViewLive: function(dpcheng) {
				/*
				<!-- IP handleDpchEngWzskLiv3DViewLive - BEGIN -->
				*/
				console.log("PnlWzskLiv3DView.handleDpchEngWzskLiv3DViewLive()" + dpcheng);
				/*
				<!-- IP handleDpchEngWzskLiv3DViewLive - END -->
				*/
			},
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWzskVDpch == "DpchEngWzskLiv3DViewLive") this.handleDpchEngWzskLiv3DViewLive(obj.dpcheng);
				else if (obj.srefIxWzskVDpch == "DpchEngWzskLiv3DViewData") this.mergeDpchEngData(obj.dpcheng);
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

			statapp: null,

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
