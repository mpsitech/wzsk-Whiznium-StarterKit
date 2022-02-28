<template>
	<v-card v-if=initdone class="pa-3 my-3 mx-auto" elevation="4">
		<v-card-title>
			<v-row>
				<v-col cols="11">
					<div>{{tag.Cpt}}</div>
				</v-col>
				<v-col align="end">
					<v-btn-toggle v-model="contapp.ButClaimOn">
						<v-btn
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
					</v-btn-toggle>
				</v-col>
			</v-row>
		</v-card-title>

		<v-card-text>
			<v-slider
				class="my-2"
				v-model="contiac.SldTrg"
				v-on:end='updateEng(["contiac"])'
				:label="tag.CptTrg"
				:min="statshr.SldTrgMin"
				:max="statshr.SldTrgMax"
				:disabled="!statshr.SldTrgActive"
			>
				<template v-slot:append>
					<v-text-field
						v-model="contiac.SldTrg"
						v-on:change='updateEng(["contiac"])'
						class="mt-0 pt-0"
						hide-details
						single-line
						type="number"
						style="width: 80px"
					/>
				</template>
			</v-slider>

		</v-card-text>
	</v-card>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWzskLlvTtable',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWzskLlvTtable.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWzskLlvTtableDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": consref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handlePupChange: function(cisref, fi) {
				this.contiac[cisref] = fi.num;

				this.updateEng(["contiac"]);
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWzskLlvTtable"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWzskLlvTtableData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWzskLlvTtableData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacWzskLlvTtable) this.contiac = dpcheng.ContIacWzskLlvTtable;
				if (dpcheng.ContInfWzskLlvTtable) this.continf = dpcheng.ContInfWzskLlvTtable;
				if (dpcheng.StatShrWzskLlvTtable) this.statshr = dpcheng.StatShrWzskLlvTtable;
				if (dpcheng.TagWzskLlvTtable) {
					Wzsk.unescapeBlock(dpcheng.TagWzskLlvTtable);
					this.tag = dpcheng.TagWzskLlvTtable;
				};

				if (dpcheng.ContInfWzskLlvTtable) {
					if (!this.continf.ButClaimOn) this.contapp.ButClaimOn = 0;
					else this.contapp.ButClaimOn = 1;
				}
				/*
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
				if (srefIxWzskVDpch == "DpchEngWzskLlvTtableData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWzskVDpch == "DpchEngWzskLlvTtableData") this.mergeDpchEngData(obj.dpcheng);
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
			contapp: {
				ButClaimOn: 0,
			},

			contiac: null,

			continf: null,

			statshr: null,

			tag: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
